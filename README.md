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


##How to use it

Before you start recording videos, you need to initialize the player using your personnal key from your [Nimbb.com account](http://nimbb.com/User/Dev/Key.aspx)

```objective-c
[NimbbPlayer initPlayerConfigurationUsingDeveloperPublicKey:@"YOURPUBLICKEY" 
  videoLength:30 
  videoQuality:NimbbPlayerQualityMedium 
  forceDev:NO 
  configurationCompletedHandler:^{
    NSLog(@"You're ready to record videos!");
}
  configurationFailedHandler:^(NSError *error) {
    NSLog(@"oh no!");
}];
```

When the player is initialized with success, you can start recording videos using only one method... and that's it!

```objective-c
[NimbbPlayer startCaptureVideoFromViewController:self
  videoUploadProgressionHandler:^(NSUInteger bytesWritten, long long totalBytesWritten, long long totalBytesExpectedToWrite) {
    float percent = ((float)totalBytesWritten / (float)totalBytesExpectedToWrite);
    NSLog(@"Uploading video... %f / 100",percent*100.0f);
}
  videoSavedHandler:^(NSString *nimbbVideoGuid) {
    NSLog(@"http://nimbb.com/v/%@", nimbbVideoGuid);
} 
  videoCanceledHandler:^{
    NSLog(@"Video canceled...");
}
  captureFailedHandler:^(NSError *error) {
    NSLog(@"oh no!");
}];
```

If you want to playback the video into your app, you need to call the [Nimbb Live/Play](http://nimbb.com/Doc/Dev/Service/Live/Play.aspx) service. Here's a sample code you could use:

```objective-c
NSURL *url= [NSURL URLWithString:[NSString stringWithFormat:@"http://api.nimbb.com/Live/Play.aspx?guid=%@&key=%@", 
                                           @"NIMBBVIDEOGUID", @"YOURPUBLICKEY"]];
MPMoviePlayerController *moviePlayerController = [[MPMoviePlayerController alloc] initWithContentURL:url];
moviePlayerController.controlStyle=MPMovieControlStyleDefault;
moviePlayerController.shouldAutoplay=YES;
[moviePlayerController setFullscreen:YES animated:YES];

```
