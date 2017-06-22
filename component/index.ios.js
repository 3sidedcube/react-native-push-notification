'use strict';

import {
  AppState,
} from 'react-native';

import RNPushNotificationIOS from "../ios/RNPushNotificationIOS";

module.exports = {
  state: AppState,
  component: RNPushNotificationIOS
};

