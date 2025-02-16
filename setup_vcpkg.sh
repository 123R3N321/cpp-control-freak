# source this script from the project root directory
# source setup_vcpkg.sh

# download and bootstrap vcpkg if not yet set up
if [ ! -d vcpkg ]
then
  git clone https://github.com/microsoft/vcpkg.git
  cd vcpkg && ./bootstrap-vcpkg.sh
  cd -
fi

# set env var for vcpkg dir and add it to PATH
if [ -z "$VCPKG_ROOT" ]; then
  export VCPKG_ROOT="$(pwd)/vcpkg"
  export PATH=$VCPKG_ROOT:$PATH
fi
