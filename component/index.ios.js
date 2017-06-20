'use strict';

import {
  AppState,
} from 'react-native';

import PushNotificationIOS from "../ios/PushNotificationIOS";

module.exports = {
  state: AppState,
  component: PushNotificationIOS
};

