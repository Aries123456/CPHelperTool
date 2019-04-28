
Pod::Spec.new do |spec|
  spec.name         = "CPHelperTool"
  spec.version      = "1.0.1"
  spec.summary      = "基础工具类"
  spec.description  = <<-DESC
  "基础工具类"
                   DESC

  spec.homepage     = "https://github.com/Aries123456"
  spec.license      = { :type => "MIT", :file => "LICENSE"}
  spec.author             = { "lk" => "348994901@qq.com" }
  spec.platform     = :ios, "8.0"
  spec.source       = { :git => "https://github.com/Aries123456/CPHelperTool.git", :tag => "#{spec.version}" }
  spec.source_files  = "CPHelperTool", "CPHelperTool/**/*.{h,m}"
  # spec.public_header_files = "CPHelperTool/**/*.{h,m}"
end
