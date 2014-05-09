//
//  ViewController.h
//  nimbbapidemo
//
//  Created by Olivier Lavoie on 5/8/2014.
//  Copyright (c) 2014 D2Soft Technologies inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController <UITextFieldDelegate>
@property (weak, nonatomic) IBOutlet UITextField *videoUrlTextField;
@property (weak, nonatomic) IBOutlet UITextView *logTextView;
@property (weak, nonatomic) IBOutlet UIButton *recordButton;

@end
