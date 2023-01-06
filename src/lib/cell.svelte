<script>
  import "../app.css";
  import Mathfield from "$lib/mathfield.svelte";
  import NaturalLanguageInput from "$lib/natural-language-input.svelte";
  let kindOfInput = "natural_language";
</script>


<div class="w-full">
  {#if kindOfInput === "natural_language"}
    <NaturalLanguageInput/>
  {/if}
  {#if kindOfInput === "latex"}
    <Mathfield/>
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
</div>



