while read -r line; do
    echo "$line" | cut -c13-
done