```
podman import lfi.tar
podman run -v ~/cpu2017/:/home/lfi/cpu2017:U -it --user lfi --workdir /home/lfi lfi /bin/bash
```
