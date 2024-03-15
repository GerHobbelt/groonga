#!/bin/sh

GRN_VERSION_SH="$(pwd)/version.sh"

case "$0" in
  */*)
    cd `dirname $0`
    ;;
esac

if test -f full_version; then
  GRN_VN=$(cat full_version)
elif test -d .git -o -f .git; then
  GRN_VN=$(git describe --abbrev=7 HEAD 2>/dev/null)
  if [ $? -ne 0 ]; then
    GRN_VN=$(cat base_version)
  fi
else
  GRN_VN=$(cat base_version)
fi

GRN_VN=$(expr "$GRN_VN" : v*'\(.*\)')

if test -r "${GRN_VERSION_SH}"; then
  GRN_VN_OLD=$(sed -E -e 's/^GRN_VERSION(_FULL)?=//' "${GRN_VERSION_SH}")
else
  GRN_VN_OLD=unset
fi

if test "$GRN_VN_OLD" != "$GRN_VN"; then
  echo "GRN_VERSION_FULL=$GRN_VN" > "${GRN_VERSION_SH}"
fi
