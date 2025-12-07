{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  name = "ez-language-native";
  packages = with pkgs; [ clang llvmPackages_latest.clang python312 cmake ninja ];
  shellHook = ''
    export CC=clang
    export CXX=clang++
  '';
}
