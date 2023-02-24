echo "Pattern:"
read Pattern
echo "Directory:"
read fpath
echo "searching $pattern in $fpath"
cd $fpath
for file in *; do
    if [ -f "$file" ] && grep -q "$pattern" "$file"; then
        echo "$file"
    fi
done