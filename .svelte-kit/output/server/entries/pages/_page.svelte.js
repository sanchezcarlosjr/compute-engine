import { c as create_ssr_component, d as add_attribute, f as createEventDispatcher, v as validate_component, i as is_promise, n as noop } from "../../chunks/index2.js";
import "mathlive";
const app = "";
const mathinput_svelte_svelte_type_style_lang = "";
const Mathfield = create_ssr_component(($$result, $$props, $$bindings, slots) => {
  let { value } = $$props;
  let mf;
  if ($$props.value === void 0 && $$bindings.value && value !== void 0)
    $$bindings.value(value);
  return `<math-field readonly${add_attribute("this", mf, 0)}></math-field>`;
});
const naturalLanguageInput_svelte_svelte_type_style_lang = "";
const css = {
  code: '.grow-wrap.svelte-1tr3wzu.svelte-1tr3wzu{display:grid}.grow-wrap.svelte-1tr3wzu.svelte-1tr3wzu::after{content:attr(data-replicated-cell) " ";white-space:pre-wrap;visibility:hidden}.grow-wrap.svelte-1tr3wzu>textarea.svelte-1tr3wzu{resize:none;overflow:hidden}.grow-wrap.svelte-1tr3wzu>textarea.svelte-1tr3wzu,.grow-wrap.svelte-1tr3wzu.svelte-1tr3wzu::after{border:1px solid palegreen;padding:0.5rem;font:inherit;grid-area:1 / 1 / 2 / 2}',
  map: null
};
const Natural_language_input = create_ssr_component(($$result, $$props, $$bindings, slots) => {
  let cell = "";
  createEventDispatcher();
  $$result.css.add(css);
  return `<div class="${"grow-wrap svelte-1tr3wzu"}"${add_attribute("data-replicated-cell", cell, 0)}><textarea placeholder="${"Enter what you want to calculate"}" data-gramm="${"false"}" rows="${"1"}" class="${"svelte-1tr3wzu"}">${""}</textarea>
</div>`;
});
const Cell = create_ssr_component(($$result, $$props, $$bindings, slots) => {
  let { alpha } = $$props;
  let result = "";
  if ($$props.alpha === void 0 && $$bindings.alpha && alpha !== void 0)
    $$bindings.alpha(alpha);
  let $$settled;
  let $$rendered;
  do {
    $$settled = true;
    $$rendered = `<div class="${"w-full"}">${`${validate_component(Natural_language_input, "NaturalLanguageInput").$$render($$result, {}, {}, {})}`}
  ${``}
  <ul class="${"items-center text-sm font-medium text-gray-900 bg-white sm:flex mt-0.5"}"><li><div class="${"flex items-center"}"><input checked id="${"natural-language"}" type="${"radio"}" name="${"list-radio"}">
        <label for="${"natural-language"}" class="${"w-full py-3 ml-2 text-sm font-medium text-gray-900 dark:text-gray-300"}">Natural Language</label></div></li>
    <li><div class="${"flex items-center pl-3"}"><input id="${"latex"}" type="${"radio"}" name="${"list-radio"}">
        <label for="${"latex"}" class="${"w-full py-3 ml-2 text-sm font-medium text-gray-900 dark:text-gray-300"}">Latex</label></div></li></ul>
  ${validate_component(Mathfield, "MathField").$$render(
      $$result,
      { value: result },
      {
        value: ($$value) => {
          result = $$value;
          $$settled = false;
        }
      },
      {}
    )}</div>`;
  } while (!$$settled);
  return $$rendered;
});
function startApp() {
  return void 0;
}
const Page = create_ssr_component(($$result, $$props, $$bindings, slots) => {
  let instancePromise = startApp();
  return `<div class="${"flex flex-row justify-center mt-6"}"><div class="${"flex flex-col w-3/6"}"><h1 class="${"text-3xl text-center"}">Alpha</h1>
    ${function(__value) {
    if (is_promise(__value)) {
      __value.then(null, noop);
      return `
      <p>waiting...</p>
    `;
    }
    return function(module) {
      return `
      ${validate_component(Cell, "Cell").$$render($$result, { alpha: module }, {}, {})}
    `;
    }(__value);
  }(instancePromise)}</div></div>`;
});
export {
  Page as default
};
