#
# Be sure to run `pod lib lint pepepod.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'PagoEfectivoSDK'
  s.version          = '0.0.9'
  s.summary          = 'SDK de PagoEfectivo'
 
 # This description is used to generate tags and improve search results.
 #   * Think: What does it do? Why did you write it? What is the focus?
 #   * Try to keep it short, snappy and to the point.
 #   * Write the description between the DESC delimiters below.
 #   * Finally, don't worry about the indent, CocoaPods strips it!
 
  s.description      = <<-DESC
  PagoEfectivoSDK le permitirá implementar de forma sencilla y rápida las funcionalidades que ofrece para realizar transacciones online a través de la plataforma de PagoEfectivo en dispositivos iPhone.
  
  En el siguiente manual encontrará todo lo necesario para poder empezar la implementación del SDK, así como la forma correcta de implementar sus principales funciones tales como Generar un CIP y Listar CIPs. 
                       DESC
 
  s.homepage         = 'https://pagoefectivo.pe'
  s.license          = { :type => 'Custom', :file => 'LICENSE' }
  s.author           = { 'PagoEfectivo' => 'developers.pagoefectivo@gmail.com' }
  s.source       = { :git => "https://github.com/PagoEfectivo/sdk-pe-ios.git", :tag => "#{s.version}" } 
  s.ios.deployment_target = '8.0'
 
  s.source_files = 'PagoEfectivoSDK/*' , 'PagoEfectivoSDK/PagoEfectivoSDK.framework/Headers/*.h'
  s.public_header_files = 'PagoEfectivoSDK/PagoEfectivoSDK.framework/Headers/*.h'
  s.exclude_files = 'PagoEfectivoSDK/*.{m,h,plist,sh}', 'PagoEfectivoSDK/PagoEfectivoSDK.framework/{Info.plist,PagoEfectivoSDK,ios-build-framework-script.sh}',
                     'PagoEfectivoSDK/PagoEfectivoSDK.framework/Modules', 'PagoEfectivoSDK/PagoEfectivoSDK.framework/_CodeSignature',
                     'PagoEfectivoSDK/PagoEfectivoSDK.framework/PagoEfectivoSDK'
    
  
  
  #s.excludee_files = 'PagoEfectivoSDK/**/*.h'
  s.vendored_frameworks = 'PagoEfectivoSDK/PagoEfectivoSDK.framework'
 
  # s.resource_bundles = {
  #   'pepepod' => ['pepepod/Assets/*.png']
  # }
 
  #s.public_header_files = 'PagoEfectivoSDK/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
 end