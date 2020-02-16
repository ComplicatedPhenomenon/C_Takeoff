if [[ -d docs ]]
then
    rm -r docs
fi

git rm -r docs 
doxygen Doxyfile
mv docs/html/* docs/ && rm -rf docs/html/
git add docs