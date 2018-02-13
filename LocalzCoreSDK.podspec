Pod::Spec.new do |s|

	s.name = 'LocalzCoreSDK'
	s.summary = 'LocalzCoreSDK'

	s.version = '0.1.0'
	s.platform = :ios,'9.0'
	s.ios.deployment_target = '9.0'
	
	s.homepage = 'http://localz.com'
	s.license = {
		:type => 'Commercial',
		:text => <<-LICENSE
			Copyright 2018 Localz Pty Ltd.
			LICENSE
	}
	s.author = { 'Localz Pty Ltd' => 'info@localz.com' }
	s.source = { :git => 'https://github.com/localz/Localz-Core-iOS-SDK.git',
				 :tag => s.version }
	
	s.requires_arc = true
	s.preserve_paths = 'LocalzCoreSDK.framework'
	s.xcconfig = { 'FRAMEWORK_SEARCH_PATHS' => '$(inherited)' }
	s.frameworks = 'SystemConfiguration','Foundation'
	s.vendored_frameworks = 'LocalzCoreSDK/LocalzCoreSDK.framework'
end
