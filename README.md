# QMK Userspace

- This config bases its OLED on the Soundmonster's implementation:
[https://github.com/soundmonster/qmk_userspace](https://github.com/soundmonster/qmk_userspace)

## Howto build locally

1. Optional. Run `setup.sh` to get the firmware repo and generate the
   `compile_commands.json`.
1. Run `make` to build the default `keyboard:keymap`: equivalent to `make
   crkbd/rev1:leobarreiro`


## Howto build with GitHub on push

1. When you push a new commit just make sure to update the tag to latest and
   share it with origin.

``` bash
git tag --delete latest && git tag latest && \
git push origin --delete latest && git push origin latest
```

***This repo is configured to only build on latest tags and manually runs***

## Howto build with GitHub manually

1. In the GitHub Actions tab, enable workflows
1. Push your changes above to your forked GitHub repository
1. Look at the GitHub Actions for a new action run
1. Wait for the actions run to complete
1. Inspect the Releases tab on your repository for the latest firmware build

