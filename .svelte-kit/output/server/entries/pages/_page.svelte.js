import { c as create_ssr_component, d as add_attribute, v as validate_component } from "../../chunks/index2.js";
import "mathlive";
const app = "";
const mathfield_svelte_svelte_type_style_lang = "";
const naturalLanguageInput_svelte_svelte_type_style_lang = "";
const css = {
  code: '.grow-wrap.svelte-1tr3wzu.svelte-1tr3wzu{display:grid}.grow-wrap.svelte-1tr3wzu.svelte-1tr3wzu::after{content:attr(data-replicated-cell) " ";white-space:pre-wrap;visibility:hidden}.grow-wrap.svelte-1tr3wzu>textarea.svelte-1tr3wzu{resize:none;overflow:hidden}.grow-wrap.svelte-1tr3wzu>textarea.svelte-1tr3wzu,.grow-wrap.svelte-1tr3wzu.svelte-1tr3wzu::after{border:1px solid palegreen;padding:0.5rem;font:inherit;grid-area:1 / 1 / 2 / 2}',
  map: null
};
const Natural_language_input = create_ssr_component(($$result, $$props, $$bindings, slots) => {
  let cell = "";
  $$result.css.add(css);
  return `<div class="${"grow-wrap svelte-1tr3wzu"}"${add_attribute("data-replicated-cell", cell, 0)}><textarea data-gramm="${"false"}" rows="${"1"}" class="${"svelte-1tr3wzu"}">${""}</textarea>
</div>`;
});
const Cell = create_ssr_component(($$result, $$props, $$bindings, slots) => {
  return `<div class="${"w-full"}">${`${validate_component(Natural_language_input, "NaturalLanguageInput").$$render($$result, {}, {}, {})}`}
  ${``}
  <ul class="${"items-center text-sm font-medium text-gray-900 bg-white sm:flex mt-0.5"}"><li><div class="${"flex items-center"}"><input checked id="${"natural-language"}" type="${"radio"}" name="${"list-radio"}">
        <label for="${"natural-language"}" class="${"w-full py-3 ml-2 text-sm font-medium text-gray-900 dark:text-gray-300"}">Natural Language</label></div></li>
    <li><div class="${"flex items-center pl-3"}"><input id="${"latex"}" type="${"radio"}" name="${"list-radio"}">
        <label for="${"latex"}" class="${"w-full py-3 ml-2 text-sm font-medium text-gray-900 dark:text-gray-300"}">Latex</label></div></li></ul></div>`;
});
const Page = create_ssr_component(($$result, $$props, $$bindings, slots) => {
  return `<div class="${"flex flex-row justify-center mt-6"}"><div class="${"flex flex-col w-3/6"}"><h1 class="${"text-3xl text-center"}">Alpha</h1>
    ${validate_component(Cell, "Cell").$$render($$result, {}, {}, {})}</div></div>`;
});
export {
  Page as default
};
