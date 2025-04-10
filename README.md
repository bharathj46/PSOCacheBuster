# PSOCacheBuster
Clears the PSO driver cache for non-shipping and non-editor builds for easier testing and profiling of first-run-like experience.

If you want it to run in shipping builds (advanced users) then you can add this to your Config/DefaultGame.ini file:
```
[PSOCacheBuster]
bRunInShippingBuilds=false
```
If you do that, remember to NOT ship this to users.

# Installation
Copy this plugin to either your ProjectName/Plugins or Engine/Plugins folder.

Enable the plugin in the Plugins window in Unreal Editor.

# License
PSOCacheBuster is licensed under [The Unlicense](https://unlicense.org/).

TLDR: Do whatever you want with it, no need to credit me.
