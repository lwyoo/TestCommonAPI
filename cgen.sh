#!/bin/bash

BASE_DIR="$(dirname $(realpath $0))"
FIDL_DIR="$BASE_DIR/fidl"
GENERATOR_DIR="$BASE_DIR/tool"

for f in $FIDL_DIR/*.fidl; do
echo "FIDL($f) generating sources"

$GENERATOR_DIR/commonapi-generator/commonapi-generator-linux-x86_64 -sk $f
$GENERATOR_DIR/commonapi_dbus_generator/commonapi-dbus-generator-linux-x86_64 $f
echo "==========================="
done