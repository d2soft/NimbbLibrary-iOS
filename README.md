<p align="center" >
  <img src="http://service.nimbb.com/Images/logo.png" alt="Nimbb.com" title="Nimbb.com">
</p>

NimbbLibrary-iOS
================

Easily integrate video recording using Nimbb into your iOS project.


##How to install it

#### Podfile

```ruby
platform :ios, '7.0'
pod "NimbbLibrary", "~> 1.0"
```

#### Manually
You copy NimbbLib.framework from the Vendor directory into your project.

##### Requirements
NimbbLib.framework require [AFNetworking 2.x](https://github.com/AFNetworking/AFNetworking) to work. So you need to install it prior to use NimbbLib.framework. 

##### Link Binary With Libraries
You need to add the following libraries in the Build Phases -> Link Binary With Libraries:
- NimbbLib.framework
- libz.dylib
- libxml2.dylib

##### Build Settings
- Add `/usr/include/libxml2` in Header Search Paths
- Add `-ObjC` in Other Linker Flags
