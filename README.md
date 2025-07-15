
# QMK Userspace

Welcome to my QMK Userspace for the `crkbd/rev1` keyboard. This repository provides a customized configuration, including advanced OLED features based on Soundmonster's implementation and some stuff inspired by the original `crkbd/rev1`.

- For QMK-specific questions, advanced configuration, or troubleshooting, refer to the official [QMK documentation](https://docs.qmk.fm/).
- For hardware details and base documentation, see the [`crkbd/rev1` reference](https://github.com/qmk/qmk_firmware/blob/master/keyboards/crkbd/readme.md).
- OLED features are adapted from [Soundmonster's QMK Userspace](https://github.com/soundmonster/qmk_userspace).


## Local Build Instructions

1. Run `make setup` to initialize the QMK firmware and configure the local keyboard repository.
2. Run `make build` to compile the firmware and generate the `compile_commands.json` file.
3. Run `make flash` to flash the keyboard using the QMK CLI.
   - To set the handness (left/right) for split keyboards, run `make flash-eehands`. This is typically a one-time procedure unless you overwrite the EEPROM later.
4. Run `make` to perform setup and build in a single step.
5. For debugging, use `make build/flash-debug` to build or flash with debug enabled.
   - Use `qmk console` to read console messages.
   - For LED matrix debugging, check the `sweep_rgb_matrix_indices` function.


## GitHub Actions

**Note:** This repository is configured to build only on the `latest` tag and manual workflow runs.

When pushing a new commit, update the `latest` tag and push it to origin:

```bash
git tag --delete latest && git tag latest && \
git push origin --delete latest && git push origin latest
```