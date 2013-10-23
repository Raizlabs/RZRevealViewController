//
//  RZRevealViewController.h
//  Raizlabs
//
//  Created by Joe Goullaud on 2/17/12.
//  Copyright (c) 2012 Raizlabs. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum
{
    RZRevealViewControllerPositionLeft,
    RZRevealViewControllerPositionRight,
    RZRevealViewControllerPositionNone,
    RZRevealViewControllerPositionBoth
}
RZRevealViewControllerPosition;

typedef void (^RZRevealViewControllerCompletionBlock)(BOOL succeeded);


@protocol RZRevealViewControllerDelegate;

@interface RZRevealViewController : UIViewController <UIGestureRecognizerDelegate>

@property (strong, nonatomic) IBOutlet UIViewController *mainViewController;
@property (strong, nonatomic) IBOutlet UIViewController *leftHiddenViewController;
@property (strong, nonatomic) IBOutlet UIViewController *rightHiddenViewController;
// Defaults to having a basic shadow, change this view's CALayer shadow properties to adjust.
@property (strong, nonatomic) UIView *mainVCWrapperView;

@property (assign, nonatomic, readonly, getter = isLeftHiddenViewControllerRevealed) BOOL leftHiddenViewControllerRevealed;
@property (assign, nonatomic, readonly, getter = isRightHiddenViewControllerRevealed) BOOL rightHiddenViewControllerRevealed;
@property (assign, nonatomic, getter = isRevealEnabled) BOOL revealEnabled;

@property (strong, nonatomic, readonly) UIPanGestureRecognizer *revealPanGestureRecognizer;

@property (assign, nonatomic) CGFloat quickPeekHiddenOffset;                    // Defaults to self.view.bounds.size.width / 4.0
@property (assign, nonatomic) CGFloat peekHiddenOffset;                         // Defaults to self.view.bounds.size.width / 2.0
@property (assign, nonatomic) CGFloat showHiddenOffset;                         // Defaults to self.view.bounds.size.width
@property (assign, nonatomic) CGFloat revealGestureThreshold;                   // Defaults to CGFLOAT_MAX
@property (assign, nonatomic) CGFloat openRevealGestureThreashold;

@property (weak, nonatomic) id<RZRevealViewControllerDelegate> delegate;

- (id)initWithMainViewController:(UIViewController*)mainVC
        leftHiddenViewController:(UIViewController*)leftVC
        rightHiddenViewController:(UIViewController*)rightVC;

- (IBAction)showLeftHiddenViewControllerAnimated:(BOOL)animated;
- (void)showLeftHiddenViewControllerAnimated:(BOOL)animated completionBlock:(RZRevealViewControllerCompletionBlock)block;
- (void)showLeftHiddenViewControllerWithOffset:(CGFloat)offset animated:(BOOL)animated;
- (IBAction)peekLeftHiddenViewControllerAnimated:(BOOL)animated;
- (void)peekLeftHiddenViewControllerWithOffset:(CGFloat)offset animated:(BOOL)animated;
- (IBAction)hideLeftHiddenViewControllerAnimated:(BOOL)animated;
- (void)hideLeftHiddenViewControllerAnimated:(BOOL)animated completionBlock:(RZRevealViewControllerCompletionBlock)block;

- (IBAction)showRightHiddenViewControllerAnimated:(BOOL)animated;
- (void)showRightHiddenViewControllerAnimated:(BOOL)animated completionBlock:(RZRevealViewControllerCompletionBlock)block;
- (void)showRightHiddenViewControllerWithOffset:(CGFloat)offset animated:(BOOL)animated;
- (IBAction)peekRightHiddenViewControllerAnimated:(BOOL)animated;
- (void)peekRightHiddenViewControllerWithOffset:(CGFloat)offset animated:(BOOL)animated;
- (IBAction)hideRightHiddenViewControllerAnimated:(BOOL)animated;
- (void)hideRightHiddenViewControllerAnimated:(BOOL)animated completionBlock:(RZRevealViewControllerCompletionBlock)block;

@end

@protocol RZRevealViewControllerDelegate <NSObject>

@optional

- (void)revealController:(RZRevealViewController*)revealController willShowHiddenController:(UIViewController*)hiddenController position:(RZRevealViewControllerPosition)position;
- (void)revealController:(RZRevealViewController*)revealController didShowHiddenController:(UIViewController*)hiddenController position:(RZRevealViewControllerPosition)position;
- (void)revealController:(RZRevealViewController*)revealController willHideHiddenController:(UIViewController*)hiddenController position:(RZRevealViewControllerPosition)position;
- (void)revealController:(RZRevealViewController*)revealController didHideHiddenController:(UIViewController*)hiddenController position:(RZRevealViewControllerPosition)position;
- (void)revealController:(RZRevealViewController*)revealController willPeekHiddenController:(UIViewController*)hiddenController position:(RZRevealViewControllerPosition)position;
- (void)revealController:(RZRevealViewController*)revealController didPeekHiddenController:(UIViewController*)hiddenController position:(RZRevealViewControllerPosition)position;

@end


@interface UIViewController (RZRevealViewController) <RZRevealViewControllerDelegate>

@property (weak, nonatomic, readonly) RZRevealViewController *revealViewController;

@end
