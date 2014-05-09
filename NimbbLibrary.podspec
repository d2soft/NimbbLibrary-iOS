Pod::Spec.new do |s|
  s.name             = "NimbbLibrary"
  s.version          = "1.0.0"
  s.summary          = "Easily integrate video recording using Nimbb into your iOS project."
  s.homepage         = "https://github.com/d2soft/NimbbLibrary-iOS"
  s.license          = 'MIT'
  s.author           = { "D2Soft Technologies Inc." => "support@nimbb.com" }
  s.social_media_url = 'https://twitter.com/d2soft'

  s.platform     = :ios, '7.0'
  s.requires_arc = true
  
  s.dependency 'AFNetworking', '~> 2.0'
  
  s.library = 'xml2'
  s.xcconfig = { 'HEADER_SEARCH_PATHS' => '/usr/include/libxml2' }
  
  s.source   = { :http => 'http://www.vibr8soft.com/pod/NimbbLib.framework_1.0.0.zip' }
  s.source_files = 'NimbbLib.framework/Versions/A/Headers/*.h'
  s.preserve_paths = 'NimbbLib.framework/*'
  s.frameworks   = 'NimbbLib'
  s.xcconfig     = { 'FRAMEWORK_SEARCH_PATHS' => '"$(PODS_ROOT)/NimbbLib"' }
end
