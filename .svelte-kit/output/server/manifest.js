export const manifest = {
	appDir: "_app",
	appPath: "_app",
	assets: new Set(["app.wasm","favicon.png"]),
	mimeTypes: {".wasm":"application/wasm",".png":"image/png"},
	_: {
		entry: {"file":"_app/immutable/start-9f7be75b.js","imports":["_app/immutable/start-9f7be75b.js","_app/immutable/chunks/index-7f3551f2.js","_app/immutable/chunks/singletons-c1916556.js"],"stylesheets":[],"fonts":[]},
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
