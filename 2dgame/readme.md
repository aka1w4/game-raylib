### Package yang di Perlukan

Windows (mingw):
```cmd
pacman -Syu
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make mingw-w64-x86_64-pkg-config mingw-w64-x86_64-raylib
```

NixOs:
```bash
nix-env -iA nixos.gcc nixos.gnumake nixos.pkg-config nixos.raylib
```
or using nix-shell:
```bash
nix-shell
```
