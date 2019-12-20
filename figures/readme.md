* Move all the `xmind` figure in directory of `figures`.
    ```sh
    find . -name '*.xmind' | xargs -I '{}' mv {} figures
    ```