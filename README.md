# Raytrace

### **実行環境**
Ubuntu 18.04</br>
以下のツールを利用するので、installします。
```
sudo apt-get install gcc make perl
sudo apt-get install libx11-dev
sudo apt-get install libxext-dev
```
### **Intall**
```
git clone https://github.com/M1-koda/Raytrace.git
```
### **説明**
本プログラムは、レイトレーシングと呼ばれる方法を用いて指定された物体(rt_file)のレンダリングを行っている。</br>
レイトレーシングは光点からの光線を追跡し、物体による光の反射を計算することでカメラの位置から見える物体の3D表現をシミュレーションする方法である。

![レイトレーシング](fundamental%20shape/method.png?raw=true)

本プログラムでは、表現できる物体の形を6つ{球,平面(無限に広がる),円筒,三角形平面,四角形平面,円錐}用意した。
これらの物体を利用したレンダリングを以下の例題に紹介する。

### **実行方法**
make: raytracingが作成される。
```
make 
./raytracing [path-to-rt_file]
```
オブジェクトファイルを消去したい場合、
```
make clean
```
---
### **rtファイル**
rtファイルとは、レンダリングの際に必要となるパラメータを設定するファイルである。</br>
例えば、物体の位置やカメラの位置、光の位置、レンダリングの解像度を決めている。</br>
以下にrtファイルで設定できるパラメータを記載する。</br>

**`<注意>`**</br>
パラメータの先頭文字**R, A, C**はrtファイル内で一度しか宣言できなようにしている。</br>
また、各パラメータの引数は空白(スペース)で区切られている必要がある。</br>
先頭に'#'をつけることでコメントアウトできる</br>

「整数」の引数に「実数」を、「実数」の引数に「整数」を入力した場合は引数エラーとなる。</br>
また、知らないパラメータを入力した場合、引数エラーとなる。

<details>
<summary> 解像度 </summary>

出力されるウィンドウサイズ(H x W) H,Wは整数とする。</br>
```
Ex)
R W_size H_size
R 500 500
```
</details>

<details>
<summary> 環境光 </summary>

環境光はレンダリングである物体を映し出すときに、他の物体からの反射を考慮して加えられる定数である。</br>
```
Ex)
A A_ratio RGB_value
A 0.2 255,255,255
```
第2引数は、環境光の強さ(0 ≦ x ≦ 1, 実数)</br>
第3引数は、環境光の色(0 ≦ x ≦ 255, 整数)</br>
を指定している。</br>
</details>

<details>
<summary> カメラ </summary>

カメラの位置(レンダリングの処理を行う3次元の位置、方向を決める)を決めるパラメータを渡すコマンド。</br>
```
Ex)
C カメラ座標 カメラの向き(正規化されるvector) FOV
C 0.0,0,1 0,0,-1 70
```
第2引数は、カメラ座標(カメラの位置, 実数)</br>
第3引数は、カメラの向き(任意の実数を','で区切り指定する。ここでのvector値はプログラム内で自動的に正規化される, 実数)</br>
第4引数は、FOV(field of view):水平方向の画角(0 ≦ x ≦ 180, 整数)</br>
</details>

<details>
<summary> ライト </summary>

```
Ex)
l ライトの座標 ライトの強さ RGB_value
l -40.0,50.0,0.0 0.6 10,0,255
```
第2引数は、ライト座標(ライトの座標, 実数)</br>
第3引数は、環境光の強さ(0 ≦ x ≦ 1, 実数)</br>
第4引数は、環境光の色(0 ≦ x ≦ 255, 整数)</br>
</details>

<details>
<summary> 球 </summary>

```
Ex)
sp 球の中心座標 球の直径 RGB_value
sp 0.0,0.0,20.6 12.6 10,0,255
```
第2引数は、球の座標(実数)</br>
第3引数は、球の直径(0 ≦ x, 実数)</br>
第4引数は、球の色(0 ≦ x ≦ 255, 整数)</br>
</details>

<details>
<summary> 平面(無限の広がり) </summary>

```
Ex)
pl 平面の座標 平面の方線 RGB_value
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
```
第2引数は、平面の座標(実数):ある平面が通る座標</br>
第3引数は、平面の方線(任意の実数を','で区切り指定)</br>
第4引数は、平面の色(0 ≦ x ≦ 255, 整数)</br>
</details>

<details>
<summary> 正方形 </summary>

```
Ex)
sq 正方形の座標 正方形の方線 正方形の辺　RGB_value
sq 0.0,0.0,20.6 1.0,0.0,0.0 5.0 255,0,255
```
第2引数は、正方形の座標(実数):正方形が通る座標</br>
第3引数は、正方形の方線(任意の実数を','で区切り指定)</br>
第4引数は、正方形の辺の長さ(実数)</br>
第5引数は、正方形の色(0 ≦ x ≦ 255, 整数)</br>
</details>

<details>
<summary> 円筒 </summary>

```
Ex)
cy 円の中心座標 円筒の方向ベクトル　円筒の直径　円筒の長さ　RGB_value
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42　10,0,255
```
第2引数は、円の中心座標(任意の実数を','で区切り指定,実数)</br>
第3引数は、円筒の方向ベクトル(任意の実数を','で区切り指定)</br>
第4引数は、円筒の直径(実数)</br>
第5引数は、円筒の長さ(実数)</br>
第6引数は、円筒の色(0 ≦ x ≦ 255, 整数)</br>
</details>

<details>
<summary> 三角形 </summary>

```
Ex)
tr 三角形の1点目 三角形の2点目 三角形の3点目
tr 10.0,20.0,10.0 10.0,10.0,20.0 20.0,10.0,10.0 0,0,255
```
第2引数は、三角形の1点目座標(任意の実数を','で区切り指定,実数)</br>
第3引数は、三角形の2点目座標(任意の実数を','で区切り指定,実数)</br>
第4引数は、三角形の3点目座標(任意の実数を','で区切り指定,実数)</br>
</details>

---
### 基本の形
1. 球
2. 平面（無限に広がる）
3. 円筒
4. 三角形平面
5. 四角形平面
6. 円錐

### 例題


