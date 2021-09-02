## Steps for setup

1. Change the node version using nvm command
2. run a bunch of below export commands in the terminal

export ANDROID_SDK_ROOT=~/Library/Android/sdk/
export ANDROID_HOME=~/Library/Android/sdk/
export PATH=$ANDROID_HOME/emulator:$PATH
export PATH=$ANDROID_HOME/tools:$PATH
export PATH=$ANDROID_HOME/tools/bin:$PATH
export PATH=$ANDROID_HOME/platform-tools:$PATH

-> After init the app, you will need to link the assets and you can do so by running the command - npx react-native link

## Important commands

-> Initialize a project - `npx react-native init <project-name>`
-> Start react native server - `npx react-native start`
-> Start Android version for react native - `npx react-native run-android`
-> Start iOS version for react native -  `npx react-native run-ios`

-> To link react native vector icons - `npx react-native link react-native-vector-icons`

### To install pods (only for iOS)

-> cd ios && pod install && cd ..

## Debugging

-> To open debugger menu for react-native, try going to browser link - http://localhost:8081/debugger-ui/

## Installing Dependencies

-> You can install all the react-navigation at once using the below command

```
npm install @react-navigation/native react-native-reanimated react-native-gesture-handler react-native-screens react-native-safe-area-context @react-native-community/masked-view @react-navigation/stack @react-navigation/bottom-tabs
```

-> To install and provide gradient effect

```
npm install react-native-linear-gradient
```

## Installing @unimodules and setting up LinearGradient

-> Refer this link - https://docs.expo.io/bare/installing-unimodules/
-> npm install expo-linear-gradient
-> start using the library

## Installing camera related functionality

-> npm install react-native-camera --save
-> cd ios && pod install && cd ..

### react-native-vector-icons


## Troubleshooting

### [Error] - 'Multiple commands produce /HomeRentalClone-ffvfuybrqngbdufbohbkmhzzahcf/Build/Products/Debug-iphonesimulator/HomeRentalClone.app/Zocial.ttf':' error because of font related dependency

**Fix**

Modify `node_modules/react-native-vector-icons/react-native-config.js` to the following
```
module.exports = {
  dependency: {
    assets: [],
  },
};
```

Inside `node_modules/react-native-vector-icons/RNVectorIcons.podspec`, remove the `s.resources = "Fonts/*.ttf"` line entirely.

```
require 'json'
version = JSON.parse(File.read('package.json'))["version"]

Pod::Spec.new do |s|

  s.name           = "RNVectorIcons"
  s.version        = version
  s.summary        = "Customizable Icons for React Native with support for NavBar/TabBar, image source and full styling."
  s.homepage       = "https://github.com/oblador/react-native-vector-icons"
  s.license        = "MIT"
  s.author         = { "Joel Arvidsson" => "joel@oblador.se" }
  s.platforms      = { :ios => "9.0", :tvos => "9.0" }
  s.source         = { :git => "https://github.com/oblador/react-native-vector-icons.git", :tag => "v#{s.version}" }
  s.source_files   = 'RNVectorIconsManager/**/*.{h,m}'
  s.preserve_paths = "**/*.js"
  s.dependency 'React'

end
```

After this run

`cd ios && pod install && cd ..`

and then

`npx react-native link react-native-vector-icons`

and then build the app, it should run without any errors.
