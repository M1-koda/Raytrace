# Raytrace

### 実行環境
Ubuntu 18.04</br>
以下のツールを利用するので、installします。
```
sudo apt-get install gcc make perl
sudo apt-get install libx11-dev
sudo apt-get install libxext-dev
```
### Intall
```
git clone https://github.com/M1-koda/Raytrace.git
```
### 説明
本プログラムは、レイトレーシングと呼ばれる方法を用いて指定された物体(rt_file)のレンダリングを行っている。</br>
レイトレーシングは光点からの光線を追跡し、物体による光の反射を計算することでカメラの位置から見える物体の3D表現をシミュレーションする方法である。

![レイトレーシング](fundamental%20shape/method.png?raw=true)

本プログラムでは、表現できる物体の形を6つ{球,平面(無限に広がる),円筒,三角形平面,四角形平面,円錐}用意した。
これらの物体を利用したレンダリングを以下の例題に紹介する。

### 実行方法
make: raytracingが作成される。
```
make 
./raytracing [path-to-rt_file]
```
オブジェクトファイルを消去したい場合、
```
make clean
```

### rtファイル
rtファイルとは、レンダリングの際に必要となるパラメータを設定するファイルである。</br>
例えば、物体の位置やカメラの位置、光の位置、レンダリングの解像度を決めている。</br>
以下にrtファイルで設定できるパラメータを記載する。</br>

**<注意>**
パラメータの先頭文字**R, A, C**はrtファイル内で一度しか宣言できなようにしている。
また、各パラメータの引数は空白(スペース)で区切られている必要がある。

#### 解像度
出力されるウィンドウサイズ(H x W) H,Wはint型とする。
```
Ex)
R W_size H_size
R 500 500
```

#### 環境光
環境光はレンダリングである物体を映し出すときに、他の物体からの反射を考慮して加えられる定数である。
```
Ex)
A A_ratio RGB_value
A 0.2 255,255,255
```
第3引数は環境光の色を指定している。

#### カメラ
カメラの位置(レンダリングの処理を行う3次元の位置、方向を決める)を決めるパラメータを渡すコマンド。
```
 -50.0,0,20 0,0,1 70
```


### 基本の形
1. 球
2. 平面（無限に広がる）
3. 円筒
4. 三角形平面
5. 四角形平面
6. 円錐

### 例題


