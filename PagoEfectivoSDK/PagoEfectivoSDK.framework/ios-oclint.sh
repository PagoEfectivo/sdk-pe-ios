echo "/*==start ${CONFIGURATION} on ${SRCROOT} OCLint===*/"
if [ -z "${SCHEME+x}" ]
then
export SCHEME="${PROJECT_NAME}"
fi
cd "${SOURCE_ROOT}"
if ! which -s oclint-json-compilation-database
then
echo 'error: OCLint not installed, install e.g. with homebrew cask'
exit 2
fi

#export the tmp file
export OCLINT_TEMP_FOLDER="${SOURCE_ROOT}/tmp-oclint"
# Cleanup before building
rm -f compile_commands.json
xcodebuild clean

# Build and analyze
# OCLint Rule Index: http://docs.oclint.org/en/dev/rules/index.html
# xctool -workspace "${PROJECT_NAME}.xcworkspace" -scheme "${SCHEME}" -reporter json-compilation-database:compile_commands.json build
xcodebuild -project "${PROJECT_NAME}.xcodeproj" -scheme PagoEfectivoSDK -derivedDataPath "${OCLINT_TEMP_FOLDER}" build | tee xcodebuild.log | xcpretty -r json-compilation-database -o compile_commands.json
du -h compile_commands.json

#generate compile_commands is the key for the next sentence
oclint-json-compilation-database -e Pods -v -- -max-priority-1=100000 -max-priority-2=100000 -max-priority-3=100000 \
-disable-rule=InvertedLogic \
-disable-rule=UnusedMethodParameter \
-disable-rule=LongLine \
-disable-rule=LongVariableName \
-disable-rule=ShortVariableName \
-disable-rule=UselessParentheses \
-disable-rule=IvarAssignmentOutsideAccessorsOrInit | sed 's/\(.*\.\m\{1,2\}:[0-9]*:[0-9]*:\)/\1 warning:/'

# Final cleanup
rm -f xcodebuild.log
rm -f compile_commands.json
rm -fr "${OCLINT_TEMP_FOLDER}"
echo "/*==end ${CONFIGURATION} on ${SRCROOT} OCLint===*/"
