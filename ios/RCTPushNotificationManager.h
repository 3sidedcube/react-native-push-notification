/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <React/RCTEventEmitter.h>
#import <UserNotifications/UserNotifications.h>

extern NSString *const RCTRemoteNotificationReceived;

@interface RCTPushNotificationManager : RCTEventEmitter

typedef void (^RCTRemoteNotificationCallback)(UIBackgroundFetchResult result);
typedef void (^RCTWillPresentNotificationCallback)(UNNotificationPresentationOptions options);
typedef void (^RCTNotificationResponseCallback)(void);

#if !TARGET_OS_TV
+ (void)didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings;
+ (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
+ (void)didReceiveNotificationResponse:(UNNotificationResponse *)response completionHandler:(RCTNotificationResponseCallback)completionHandler;
+ (void)didReceiveRemoteNotification:(NSDictionary *)notification;
+ (void)didReceiveRemoteNotification:(NSDictionary *)notification fetchCompletionHandler:(RCTRemoteNotificationCallback)completionHandler;
+ (void)willPresentNotification:(UNNotification *)notification showCompletionHandler:(RCTWillPresentNotificationCallback)completionHandler;
+ (void)didReceiveLocalNotification:(UILocalNotification *)notification;
+ (void)didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;
#endif

@end
