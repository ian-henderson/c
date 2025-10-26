#!/usr/bin/env fish

if ! type -q make
    echo "Make not installed. Exiting."
    exit 1
end

if ! type -q bear
    echo "Bear not installed. Exiting."
    exit 1
end

make clean

bear -- make

echo "Generated compile_commands.json!"
