#include "incs/mlx/mlx.h"
#include <stdlib.h>

// ウィンドウサイズ
#define WIN_WIDTH 400
#define WIN_HEIGHT 300

// 閉じるボタンが押された時の処理
int on_close(void *param) {
    (void)param; // 未使用変数
    exit(0);
}

// キーが押された時の処理（例：ESCで終了）
int on_key(int keycode, void *param) {
    (void)param;
    if (keycode == 53) { // macOSのESCキー
        exit(0);
    }
    return 0;
}

int main(void) {
    // ① MiniLibXの初期化
// mlxはMinilibx内部の描画システム(接続)を表すポインタ
// ウィンドウごとに番号が与えられるのではなく、
// mlxひとつに対して複数ののウィンドウを開くことができる
// mlxはウィンドウシステムへの接続情報を保持するMinilibxのコンテキストポインタ
    void *mlx = mlx_init();

    // ② ウィンドウの作成（サイズ400x300、タイトルつき）
// mlx_new_windowはウィンドウの作成をする関数
// 第一引数はmlx（ファイルディスクリプタ）みたいなもの
// 第二引数はウィンドウの幅
// 第三引数はウィンドウの高さ
// 第四引数はウィンドウの名前を見ることができる
    void *win = mlx_new_window(mlx, WIN_WIDTH * 2, WIN_HEIGHT * 2, "mlx_demo");

    // ③ 空の画像を作成（メモリ上のピクセル領域）
// ウィンドウに表示される画像のサイズが引数となっている
    void *img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);

    // ④ 画像のピクセルバッファ情報を取得
    int bpp, size_line, endian;
    char *data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	// これは構造体で管理したほうが良さそう

    // ⑤ 画像全体を塗りつぶす（ここでは灰色）
    for (int y = 0; y < WIN_HEIGHT; y++) {
        for (int x = 0; x < WIN_WIDTH; x++) {
            int i = y * size_line + x * (bpp / 8);
            data[i + 0] = 0x50; // Blue
            data[i + 1] = 0x50; // Green
            data[i + 2] = 0x50; // Red
        }
    }


    // ⑥ 作成した画像をウィンドウに貼る
    mlx_put_image_to_window(mlx, win, img, 0, 0);

    // ⑦ 文字列をウィンドウ上に描画
// 第三引数、第四引数は文字列のスタート位置
    mlx_string_put(mlx, win, 50, 200, 0xFFFFFF, "Hello MiniLibX");

    // ⑧ 閉じるボタン（☒）が押された時の処理を設定
// イベント17はウィンドウのバツボタンに相当する
// on_closeはなにでしょうか
    mlx_hook(win, 17, 0, on_close, NULL); // イベント17はウィンドウを閉じる

    // ⑨ キーが押された時の処理（例：ESCで終了）
// on_keyはなんでしょうか
    mlx_key_hook(win, on_key, NULL);

    // ⑩ イベントループを開始（ここで止まってイベントを待つ）
// これはなんのためにやるのでしょうか
    mlx_loop(mlx);

    return 0;
}
