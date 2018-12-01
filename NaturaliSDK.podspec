#3
Pod::Spec.new do |s|

  s.name         = "NaturaliSDK"
  s.version      = "0.0.1"
  s.summary      = "NaturaliSDK"

  s.description  = <<-DESC
      NaturaliSDK is sdk for naturali features about dhl and asr
                   DESC

  s.homepage     = "https://www.naturali.io"
  s.source       = {:git => "https://github.com/jfang137/naturali_sdk_source.git", :tag => '0.0.1.2'}
  s.license      = { :type => 'naturali私有', :text => <<-LICENSE
                      Copyright 2018
                      naturali私有
                    LICENSE
                    }
  s.author       = { 'fy' => 'yi.fang@naturali.io' }

  s.platform     = :ios, '8.0'
  s.source_files = 'include/*.h'
  s.vendored_libraries = 'libNaturaliSDK.a'
  s.frameworks = 'AudioToolbox'

  s.dependency 'Protobuf'
  s.dependency 'gRPC-ProtoRPC'

end
