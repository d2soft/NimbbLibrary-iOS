//
//  NimbbPlayer.h
//  Nimbb iOS Api
//
//  Created by Olivier Lavoie on 2012-11-04.
//  Copyright (c) 2012 D2Soft Technologies Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CustomDefinitions.h"

@interface NimbbPlayer : NSObject<UIImagePickerControllerDelegate,UINavigationControllerDelegate>

/************************************
* initPlayerConfigurationUsingDeveloperPublicKey
*
*
* publicKey : your public key (can be found here: http://nimbb.com/User/Dev/Key.aspx)
* length : restrict the video lenght of your users (can be overrided by the server if you set this value out of bound of your current plan)
* videoQuality: nimbbPlayerQualityLow or NimbbPlayerQualityMedium (can be overrided by the server if you set this value out of bound of your current plan)
* isForceDev: force dev mode. When set to true, you will have some debug logs from the lib (don't release your app with this flag set to true.)
* completeBlock: block to be called if the player configuration is done successfully
* failBlock: block to be called if the player configuration failed
************************************/
+ (void)initPlayerConfigurationUsingDeveloperPublicKey:(NSString *)publicKey videoLength:(NSInteger)length videoQuality:(NimbbPlayerQuality)quality forceDev:(BOOL)isForceDev configurationCompleteHandler:(ConfigurationCompletedBlock)completeBlock configurationFailedHandler:(FailDetailsBlock)failBlock;

/************************************
* startCaptureVideoFromViewController
* !! make sure to init the player configuration prior to call this method !!
*
* controller : parent view controller to be used as delegate
* videoUploadProgressionBlock : block to track the upload progression
* videoSavedBlock : block to be called after the upload, you'll receive the Nimbb.com video guid
* videoCanceledBlock : block to be called if the user cancel the recording process
* failBlock : block to be called if the upload process fail
************************************/
+(void) startCaptureVideoFromViewController:(UIViewController*)controller videoUploadProgressionHandler:(VideoUploadProgressionBlock)videoUploadProgressionBlock videoSavedHandler:(VideoSavedBlock)videoSavedBlock videoCanceldHandler:(VideoWasCanceledBlock)videoCanceledBlock captureFailedHandler:(FailDetailsBlock)failBlock;

/************************************
* Access the singleton if you
* need to customize public property
************************************/
+ (NimbbPlayer *)sharedInstance;

@property(nonatomic, strong) NSString *developerPublicKey;
@property(nonatomic, strong) UIViewController *controllerDelegate;

#pragma mark - Blocks
@property (nonatomic, copy) FailDetailsBlock captureFailBlock;
@property (nonatomic, copy) VideoSavedBlock captureSavedBlock;
@property (nonatomic, copy) VideoUploadProgressionBlock captureUploadProgressionBlock;
@property (nonatomic, copy) VideoWasCanceledBlock captureUploadWasCanceledBlock;

@end