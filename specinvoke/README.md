To install this modified specinvoke:

```
mv version.txt version.old.txt
echo '0.0.0' > version.txt
mv bin/specinvoke bin/specinvoke.orig
mv /path/to/lfi/specinvoke ./bin/specinvoke
export SPEC_NOCHECK=1
```
