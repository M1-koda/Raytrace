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

[レイトレーシング](https://github.com/M1-koda/Raytrace/fundamental shape/method.png)

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
以下にrtファイルで設定できる

#### 解像度
出力されるウィンドウサイズ(H x W) H,Wはint型とする。
```
Ex)
R 500 500
```

#### 環境光

```
A 0.2 255,255,255
```



### 基本の形
1. 球
2. 平面（無限に広がる）
3. 円筒
4. 三角形平面
5. 四角形平面
6. 円錐

### 例題


