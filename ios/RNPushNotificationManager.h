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

extern NSString *const RNRemoteNotificationReceived;

@interface RNPushNotificationManager : RCTEventEmitter

typedef void (^RNRemoteNotificationCallback)(UIBackgroundFetchResult result);
typedef void (^RNWillPresentNotificationCallback)(UNNotificationPresentationOptions options);
typedef void (^RNNotificationResponseCallback)(void);

#if !TARGET_OS_TV
+ (void)didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings;
+ (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;
+ (void)didReceiveNotificationResponse:(UNNotificationResponse *)response completionHandler:(RNNotificationResponseCallback)completionHandler;
+ (void)didReceiveRemoteNotification:(NSDictionary *)notification;
+ (void)didReceiveRemoteNotification:(NSDictionary *)notification fetchCompletionHandler:(RNRemoteNotificationCallback)completionHandler;
+ (void)willPresentNotification:(UNNotification *)notification showCompletionHandler:(RNWillPresentNotificationCallback)completionHandler;
+ (void)didReceiveLocalNotification:(UILocalNotification *)notification;
+ (void)didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;
#endif

@end
