#include <SDL.h>
#include <SDL_image.h>

int main(int argc, char* argv[]) {
	#pragma region 初期化処理
	// SDLの初期化
	int init_result = SDL_Init(SDL_INIT_EVERYTHING);
	if (init_result != 0) {
		SDL_Log("SDLの初期化に失敗: %s", SDL_GetError());
		return -1;
	}
	// ウインドウの作成
	SDL_Window* window = SDL_CreateWindow(
		u8"SDL2雛型", // 名前
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // ウインドウの場所
		1024, 768, // ウインドウの大きさ
		0 // ウインドウのフラグ（特になければ0）
	);
	if (!window) {
		SDL_Log("ウインドウの作成に失敗: %s", SDL_GetError());
		return -1;
	}
	// レンダラの作成
	SDL_Renderer* renderer = SDL_CreateRenderer(
		window, // 描画対象
		-1, // レンダリングドライバのインデックス（普通は-1）
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC // レンダラのフラグ
	);
	if (!renderer) {
		SDL_Log("レンダラの作成に失敗: %s", SDL_GetError());
		return -1;
	}
	#pragma endregion

	#pragma region アセットの読み込み
	SDL_Surface* image1 = IMG_Load("Assets/sample1.png"); // 画像の読み込み
	if (!image1) {
		SDL_Log("画像の読み込みに失敗: %s", IMG_GetError());
	}
	#pragma endregion

	#pragma region メインループ
	bool is_running = true;
	while (is_running) {
		#pragma region 入力処理
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
			case SDL_QUIT: // ウインドウの終了ボタンが押されたとき
				is_running = false;
				break;
			default:
				break;
			}
		}
		const Uint8* keyboard_state = SDL_GetKeyboardState(NULL); // キーボードの状態を取得
		if (keyboard_state[SDL_SCANCODE_ESCAPE]) { // エスケープキーが押されているとき
			is_running = false;
		}
		#pragma endregion

		#pragma region 描画処理
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // 描画色指定
		SDL_RenderClear(renderer); // 裏画面を消去

		SDL_Texture* texture1 = SDL_CreateTextureFromSurface(renderer, image1); // 読み込んだ画像からテクスチャを生成
		SDL_Rect dstrect;//描画先の長方形
		dstrect.x = 10;
		dstrect.y = 10;
		SDL_QueryTexture(texture1, NULL, NULL, &dstrect.w, &dstrect.h); // テクスチャーの幅と高さを取得
		SDL_RenderCopy(
			renderer, // 描画先
			texture1, // 描画元
			nullptr, // 描画元の位置（nullptrで全体を描画）
			&dstrect // 描画先の位置（nullptrで全体に描画）
		);

		SDL_RenderPresent(renderer); // 裏画面と表画面を入れ替え
		#pragma endregion
	}
	#pragma endregion

	#pragma region アセットの解放
	SDL_FreeSurface(image1);
	#pragma endregion

	#pragma region 終了処理
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	#pragma endregion

	return 0;
}
