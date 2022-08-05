```bash
wget -N https://github.com/conda-forge/miniforge/releases/latest/download/Miniforge3-Linux-x86_64.sh
bash Miniforge3-Linux-x86_64.sh  -b -p opt/conda
source opt/conda/bin/activate
conda install -y 'gxx_linux-64>=12' cmake
conda install -y --channel https://roq-trading.com/conda/unstable roq-client roq-oss-abseil-cpp
git clone https://github.com/thraneh/rw-vwap
cd rw-vwap
cmake .
make
```
