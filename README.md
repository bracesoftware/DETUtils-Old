# SA:MP-DET Utilities | Information
Hi! Welcome to *SA:MP-DET Utilities* "read me" file. In general, *samp-detutils* contain libraries that have in-game visible effects and libraries that contain new scripting features. 
- Below, you can find information about each library.

## Examples

- [View](d_example.md) one simple example of script made using **SA:MP-DET Utilities**.

## Warnings
1. Do not use *d_data.inc*, it's pretty useless and will enable developer mode after including. **d_data** was supposed to be user system, but I said "no" to myself and put some random things. 
## Docs
Click on blue text to see all information about each feature.
### Installation
- Learn more about [installation](d_installation.md)...
### Libraries
- Learn more: [d_commands.inc](d_commands.md)
- Learn more: [d_interiors.inc](d_interiors.md)
- Learn more: [d_fmargs.inc](d_fmargs.md)
### Extra bonus
- Read more here: [Extra stuff](d_extra.md)
## Tests
To make sure everything works, we do tests and upload here - obviously.

Check out test files here:

- [Go to tests...](https://github.com/DentisT-SAMP/samp-detutils/tree/master/tests)

## Troubleshooting

If you're facing problems like function failed to call, function is not valid, critical errors - make sure you enable automatic debugging.
- Automatic debugging literally sends debug messages whenever it needs to.
- With this feature you can easily track problems and report them on Discord or try to troubleshoot them yourself.

To enable A.D. feature, use:

```pawn
#define detutils_debug
```

To join Discord server, [click here...](https://discord.gg/samp)

### Thanks

- Big thanks to *open.mp* community for helping me during library development.

### SA:MP DEntisT's Utilities

Legal:

- Version: MPL 1.1
    
    The contents of this file are subject to the Mozilla Public License Version 
    1.1 the "License"; you may not use this file except in compliance with 
    the License. You may obtain a copy of the License at 
    http://www.mozilla.org/MPL/
    
    Software distributed under the License is distributed on an "AS IS" basis,
    WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
    for the specific language governing rights and limitations under the
    License.
    
    The Original Code is SA:MP | DETUtils.
    
    The Initial Developer of the original code is DEntisT 'Unity' Brace.
    Portions created by the Initial Developer are Copyright C 2021
    the Initial Developer. All Rights Reserved.

Contributors:

- DEntisT

Thanks:
- open.mp team - ideas, support, help during development

Very special thanks to:

- Thiadmer - PAWN, whose limits continue to amaze me!

- Kye/Kalcor - SA:MP

- SA:MP Team past, present and future - SA:MP

- open.mp team present and future - SA:MP

Optional plugins:

- Incognito - streamer
