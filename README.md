# QMK Userspace

- Check base documentation for: `crkbd/rev1`
[https://github.com/qmk/qmk_firmware/blob/master/keyboards/crkbd/readme.md](https://github.com/qmk/qmk_firmware/blob/master/keyboards/crkbd/readme.md)]

- This config bases its OLED on the Soundmonster's implementation:
[https://github.com/soundmonster/qmk_userspace](https://github.com/soundmonster/qmk_userspace)

## Howto build locally

1. Run `make setup` to setup the QMK firmware and configure the local keyboard repo.
2. Run `make build` to compile and generate the `compile_commands.json` file.`
3. Run `make flash` to flash the keyboard using the QMK CLI.
4. Run `make`to setup and build at once.

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

