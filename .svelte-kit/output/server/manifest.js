export const manifest = {
	appDir: "_app",
	appPath: "_app",
	assets: new Set(["app.wasm","favicon.ico"]),
	mimeTypes: {".wasm":"application/wasm",".ico":"image/vnd.microsoft.icon"},
	_: {
		entry: {"file":"_app/immutable/start-b22ba9b8.js","imports":["_app/immutable/start-b22ba9b8.js","_app/immutable/chunks/index-e02e35d2.js","_app/immutable/chunks/singletons-2157a179.js"],"stylesheets":[],"fonts":[]},
		nodes: [
			() => import('./nodes/0.js'),
			() => import('./nodes/1.js'),
			() => import('./nodes/2.js')
		],
		routes: [
			{
				id: "/",
				pattern: /^\/$/,
				params: [],
				page: { layouts: [0], errors: [1], leaf: 2 },
				endpoint: null
			}
		],
		matchers: async () => {
			
			return {  };
		}
	}
};
