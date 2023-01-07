import { browser } from "$app/environment";

async function instantiateModule() {
  // @ts-ignore
  const instance = new Module["Engine"](10, "hello");
  return new Promise<any>((resolve) => resolve(instance));
}

export function startApp() {
  if (browser) {
    return instantiateModule();
  }
  return undefined;
}