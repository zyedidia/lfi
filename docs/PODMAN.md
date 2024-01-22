```
podman import lfi.tar
podman run -v ~/cpu2017/:/home/lfi/cpu2017:U -it --security-opt=seccomp=unconfined --user lfi --workdir /home/lfi lfi /bin/bash
podman exec -it --user lfi --workdir /home/lfi lfi /bin/bash
```
