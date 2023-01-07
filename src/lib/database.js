export function save(query, expression) {
  const url = new URL(window.location);
  url.searchParams.set(query, expression);
  window.history.pushState({}, "", url);
  return expression;
}

export function retrieve(query, defaultValue="") {
  return (new URL(document.location)).searchParams.get(query) || defaultValue;
}