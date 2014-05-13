<p align="center" >
  <img src="http://service.nimbb.com/Images/logo.png" alt="Nimbb.com" title="Nimbb.com">
</p>

NimbbLibrary-iOS
================

Easily integrate video recording using Nimbb into your iOS project.  [Nimbb](http://nimbb.com) is a turn-key all-inclusive service in the cloud that offers all the features you need to record, host and playback user generated videos inside your projects.  All videos are stored on our servers so that you focus only on the client side.  Refer to our [Pricing](http://nimbb.com/Help/Subscriptions.aspx) page for a complete feature list and price.

##Before you begin

To use the Nimbb Library for iOS, first [create](http://nimbb.com/Account/Create.aspx) your Nimbb account.  A Silver (or higher) plan is required to be able to record or playback videos from iOS.  [Contact](http://nimbb.com/Help/) us to get a trial period.

You also need to add an "iOS application" entry in your Nimbb's [Developer Settings](http://nimbb.com/User/Dev/Settings.aspx).  Specify the "Bundle ID" of your Xcode project.

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

Before you start recording videos, you need to initialize the player using your [developer key](http://nimbb.com/User/Dev/Key.aspx) from your Nimbb account.

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
  }
];
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
  }
];
```

If you want to playback the video into your app, you need to call the  [Live/Play](http://nimbb.com/Doc/Dev/Service/Live/Play.aspx) function of the Nimbb service. Here's a sample code you could use:

```objective-c
NSURL *url= [NSURL URLWithString:[NSString stringWithFormat:@"http://api.nimbb.com/Live/Play.aspx?guid=%@&key=%@", 
                                           @"NIMBBVIDEOGUID", @"YOURPUBLICKEY"]];
MPMoviePlayerController *moviePlayerController = [[MPMoviePlayerController alloc] initWithContentURL:url];
moviePlayerController.controlStyle=MPMovieControlStyleDefault;
moviePlayerController.shouldAutoplay=YES;
[moviePlayerController setFullscreen:YES animated:YES];

```

##Sample Project

You can download and test the Example project.  Make sure to add the matching project Bundle ID into the [settings](http://nimbb.com/User/Dev/Settings.aspx) of your Nimbb account (select "iOS application").  Modify the value of kPublicKey in file ViewController.m to match your [public key](http://nimbb.com/User/Dev/Key.aspx).  Run on a physical device to record with the camera.

