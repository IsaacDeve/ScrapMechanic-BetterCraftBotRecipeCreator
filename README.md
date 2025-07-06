# Better Craft Bot Recipe Creator

This program is a better version of [my old program written in C#](https://github.com/IsaacDeve/ScrapMechanic-CraftBotRecipeCreator).

It is better in many ways, it is fully rewritten in C++, thanks to which it works much faster.
It is more convenient due to new intuitive ImGui interface 


# How to use

Drag & Drop your .json recipe into the program

⚠️ **Warning:** If you are editing an existing `json` file, make sure it doesn't contain comments or extra characters (usually at the top), like
```json
// this file is generated
```
Such lines will **break** JSON parsing.

Otherwise, if you want to create a new unique recipe, create a new `.json` file anywhere on your computer and drag&drop it into the program. 


![Image](SM_BCBRC_README.png)
