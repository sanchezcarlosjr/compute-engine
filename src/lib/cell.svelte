<script>
  import "../app.css";
  import MathInput from "$lib/mathinput.svelte";
  import MathField from "$lib/mathfield.svelte";
  export let alpha;
  import NaturalLanguageInput from "$lib/natural-language-input.svelte";
  let kindOfInput = "natural_language";
  let result = "";
  function handleEnter(event) {
    const cell = event.detail.cell.trim();
    if (cell === "") {
      result = "";
      return;
    }
    result = alpha.interpret(cell);
  }
</script>


<div class="w-full">
  {#if kindOfInput === "natural_language"}
    <NaturalLanguageInput on:message={handleEnter}/>
  {/if}
  {#if kindOfInput === "latex"}
    <MathInput on:message={handleEnter}/>
  {/if}
  <ul class="items-center text-sm font-medium text-gray-900 bg-white sm:flex mt-0.5">
    <li>
      <div class="flex items-center">
        <input checked id="natural-language" on:change={() => kindOfInput = "natural_language"}  type="radio" name="list-radio">
        <label for="natural-language" class="w-full py-3 ml-2 text-sm font-medium text-gray-900 dark:text-gray-300">Natural Language</label>
      </div>
    </li>
    <li>
      <div class="flex items-center pl-3">
        <input id="latex" type="radio" on:change={() => kindOfInput = "latex"} name="list-radio">
        <label for="latex" class="w-full py-3 ml-2 text-sm font-medium text-gray-900 dark:text-gray-300">Latex</label>
      </div>
    </li>
  </ul>
  <MathField bind:value={result}></MathField>
</div>



