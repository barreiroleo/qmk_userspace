# QMK Userspace

- This config bases its OLED on the Soundmonster's implementation:
[https://github.com/soundmonster/qmk_userspace](https://github.com/soundmonster/qmk_userspace)

## Howto build locally

1. Optional. Run `setup.sh` to get the firmware repo and generate the
   `compile_commands.json`.
1. Run `make` to build the default `keyboard:keymap`: equivalent to `make
   crkbd/rev1:leobarreiro`


## Howto build with GitHub

1. In the GitHub Actions tab, enable workflows
1. Push your changes above to your forked GitHub repository
1. Look at the GitHub Actions for a new actions run
1. Wait for the actions run to complete
1. Inspect the Releases tab on your repository for the latest firmware build

