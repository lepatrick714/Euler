echo "Running deleteBinaryFiles.sh"

for d in *;
do
    (cd $d && rm -rf a.out)
done
