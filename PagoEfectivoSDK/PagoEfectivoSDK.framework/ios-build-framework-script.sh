echo "/*==START ios-build-framework-script.sh ===*/"

cleany_folder() {
if [[ -d $1 ]]; then
  rm -fr $1
fi
mkdir -p $1
}

if [[ $SF_MASTER_SCRIPT_RUNNING ]]
then
exit 0
fi

set -u
export SF_MASTER_SCRIPT_RUNNING=1

#the default scheme
export BUILD_UNIVERSAL_PATH="${SOURCE_ROOT}/build"
export BUILD_IPHONEOS="${BUILD_UNIVERSAL_PATH}/iphoneos"
export BUILD_SIMULATOR="${BUILD_UNIVERSAL_PATH}/iphonesimulator"
export DEBUG_SCHEME="DebugPagoEfectivoSDK"

cleany_folder "${BUILD_UNIVERSAL_PATH}"
#Create the building by archs
#iphoneos
cleany_folder "${BUILD_IPHONEOS}/arm"
xcodebuild -project "${PROJECT_FILE_PATH}" -scheme "${DEBUG_SCHEME}" -sdk iphoneos \
ARCHS="arm64 armv7" \
ONLY_ACTIVE_ARCH=NO \
TARGET_BUILD_DIR="${BUILD_IPHONEOS}/arm" \
build | tee xcodebuild.log | xcpretty

#iphonesimulator
cleany_folder "${BUILD_SIMULATOR}/i386"
xcodebuild -project "${PROJECT_FILE_PATH}" -scheme "${DEBUG_SCHEME}" -sdk iphonesimulator \
ARCHS="i386" \
ONLY_ACTIVE_ARCH=NO \
BUILD_DIR="${BUILD_SIMULATOR}/i386" \
build | tee xcodebuild.log | xcpretty

cleany_folder "${BUILD_SIMULATOR}/x86_64"
xcodebuild -project "${PROJECT_FILE_PATH}" -scheme "${DEBUG_SCHEME}" -sdk iphonesimulator \
ARCHS="x86_64" \
ONLY_ACTIVE_ARCH=NO \
BUILD_DIR="${BUILD_SIMULATOR}/x86_64" \
build | tee xcodebuild.log | xcpretty

#Prepare a framework template
cp -r "${BUILD_SIMULATOR}/i386/Debug-iphonesimulator/${PROJECT_NAME}.framework" \
"${BUILD_UNIVERSAL_PATH}/${PROJECT_NAME}.framework"

#combine
lipo -create "${BUILD_IPHONEOS}/arm/${PROJECT_NAME}.framework/${PROJECT_NAME}" \
"${BUILD_SIMULATOR}/i386/Debug-iphonesimulator/${PROJECT_NAME}.framework/${PROJECT_NAME}" \
"${BUILD_SIMULATOR}/x86_64/Debug-iphonesimulator/${PROJECT_NAME}.framework/${PROJECT_NAME}" \
-output "${BUILD_UNIVERSAL_PATH}/${PROJECT_NAME}.framework/${PROJECT_NAME}"

cp -fr "${BUILD_IPHONEOS}/arm/${PROJECT_NAME}.framework/Headers" \
"${BUILD_UNIVERSAL_PATH}/${PROJECT_NAME}.framework/Headers"

open $BUILD_UNIVERSAL_PATH
echo "/*==END ios-build-framework-script.sh ===*/"

