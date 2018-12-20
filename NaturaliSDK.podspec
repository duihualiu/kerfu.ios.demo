#3
Pod::Spec.new do |s|

  s.name         = "NaturaliSDK"
  s.version      = "0.0.1.3"
  s.summary      = "NaturaliSDK"

  s.description  = <<-DESC
      NaturaliSDK is sdk for naturali features about dhl and asr
                   DESC

  s.homepage     = "https://www.naturali.io"
  s.source       = {:git => "https://github.com/jfang137/naturali_sdk_source.git", :tag => '0.0.1.3'}
  s.license      = { :type => 'MIT', :text => <<-LICENSE
                   	Copyright 2018
  			Permission is granted to Naturali
                 	LICENSE
               	   }
  s.author       = { 'fy' => 'yi.fang@naturali.io' }

  s.platform     = :ios, '8.0'
  s.source_files = 'include/*.h'
  s.vendored_libraries = 'libNaturaliSDK.a'
  s.requires_arc = true
  s.library = 'c++'
  s.xcconfig = {
       'CLANG_CXX_LANGUAGE_STANDARD' => 'c++11',
       'CLANG_CXX_LIBRARY' => 'libc++'
  }
  s.frameworks = 'AudioToolbox'
  s.dependency 'Protobuf'

end
