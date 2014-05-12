//
//  ViewController.m
//  nimbbapidemo
//
//  Created by Olivier Lavoie on 5/8/2014.
//  Copyright (c) 2014 D2Soft Technologies inc. All rights reserved.
//

#import <NimbbLib/NimbbPlayer.h>
#import "ViewController.h"

NSString *kPublicKey = @"[ENTER YOUR KEY HERE]";


@interface ViewController ()
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.recordButton.enabled = NO;
    self.videoUrlTextField.delegate = self;
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    //Before doing anything with the API, you need to setup your account
    [NimbbPlayer initPlayerConfigurationUsingDeveloperPublicKey:kPublicKey videoLength:30 videoQuality:NimbbPlayerQualityMedium forceDev:YES configurationCompletedHandler:^{
        self.recordButton.enabled = YES;
        self.logTextView.text = @"Nimbb player is ready!";
        
    } configurationFailedHandler:^(NSError *error) {
        self.logTextView.text = [NSString stringWithFormat:@"ERROR // Code: %li --- Details: %@", (long)error.code, error.localizedDescription];
    }];
}

- (IBAction)didTouchRecordButton:(id)sender {
    [NimbbPlayer startCaptureVideoFromViewController:self videoUploadProgressionHandler:^(NSUInteger bytesWritten, long long totalBytesWritten, long long totalBytesExpectedToWrite) {
        dispatch_async(dispatch_get_main_queue(), ^{
            float percent = ((float)totalBytesWritten / (float)totalBytesExpectedToWrite);
            self.logTextView.text = [NSString stringWithFormat:@"Uploading video... %f / 100",percent*100.0f];
        });
    } videoSavedHandler:^(NSString *nimbbVideoGuid) {
        self.videoUrlTextField.text = [NSString stringWithFormat:@"http://nimbb.com/v/%@", nimbbVideoGuid];
        self.logTextView.text = @"Upload done...";
    } videoCanceledHandler:^{
        self.logTextView.text = @"Recording cancelled...";
    } captureFailedHandler:^(NSError *error) {
        self.logTextView.text = [NSString stringWithFormat:@"ERROR // Code: %li --- Details: %@", (long)error.code, error.localizedDescription];
    }];
}


- (IBAction)didTouchDownVideoUrlTextView:(id)sender {
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:self.videoUrlTextField.text]];
}

- (BOOL)textFieldShouldBeginEditing:(UITextField *)textField {
    return NO;
}


@end
