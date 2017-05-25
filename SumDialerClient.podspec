Pod::Spec.new do |s|
  s.name         = "SumDialerClient"
  s.version      = "0.0.1"
  s.summary      = "SumDialerClient for iOS"
  s.description  = "SumDialerClient is client for WebRTC calls."
  s.license      = { :type => 'MIT', :file => 'LICENSE' }
  s.source       = { :git => "https://github.com/vikvych/sum_dialer_client.git", :tag => s.version.to_s }
  s.homepage     = "https://safeum.com"
  s.authors      = { 'SafeUM' => 'info@safeum.com' }

  s.ios.deployment_target   = '8.0'
  s.ios.source_files        = 'Include/**/*.h'
  s.ios.public_header_files = 'Include/**/*.h'
  s.ios.header_dir          = ''
  s.ios.preserve_paths      = 'Library/libSafeUMDialerClient.a'
  s.ios.vendored_libraries  = 'Library/libSafeUMDialerClient.a'

  s.libraries = 'safeUMDialerClient'
  s.requires_arc = false
end
