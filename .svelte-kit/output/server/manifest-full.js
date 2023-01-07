export const manifest = {
	appDir: "_app",
	appPath: "_app",
	assets: new Set([".gitignore","alpha.js","alpha.wasm","favicon.ico"]),
	mimeTypes: {".js":"application/javascript",".wasm":"application/wasm",".ico":"image/vnd.microsoft.icon"},
	_: {
		entry: {"file":"_app/immutable/start-93081e2a.js","imports":["_app/immutable/start-93081e2a.js","_app/immutable/chunks/index-6a92d7be.js","_app/immutable/chunks/singletons-753cc5c4.js"],"stylesheets":[],"fonts":[]},
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
